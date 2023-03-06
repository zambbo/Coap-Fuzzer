#include <coap3/coap.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
	
	if (size < 400) return 0;

	coap_pdu_t *pdu = coap_pdu_init(0, 0, 0, size);

	if (!pdu) return 0;

	size_t token_length = data[0] << 8*1 | data[1];
	const uint8_t *token = data + 2;
	uint8_t *old_data = token+token_length;
	size_t old_size = size - token_length - 2;
	


	int ret = coap_pdu_parse(COAP_PROTO_UDP, old_data, old_size, pdu);
	if (ret < 0) {
		coap_delete_pdu(pdu);
		return 0;
	}

	
	coap_pdu_t *dup_pdu = coap_pdu_duplicate(pdu, NULL, token_length, token, 0);
	coap_delete_pdu(pdu);
	coap_delete_pdu(dup_pdu);

	return 0;
}
