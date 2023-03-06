#include <coap3/coap.h>


int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
	coap_pdu_t *pdu = coap_pdu_init(0, 0, 0, size);
	if (!pdu) {
		return 0;	
	}

	int ret = coap_pdu_parse(COAP_PROTO_UDP, (uint8_t *)data, size, pdu);

	if (ret < 0) {
		coap_delete_pdu(pdu);
		return 0;
	}

	coap_add_token(pdu, data);
	
	coap_delete_pdu(pdu);
	return 0;

}
