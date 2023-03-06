#include <coap3/coap.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
	if (size < 5) return 0;	

	coap_pdu_t *pdu = coap_pdu_init(COAP_MESSAGE_CON, COAP_REQUEST_GET, 0, size);

	if (pdu == NULL) {
		return 0;
	}

	uint16_t opt_num = (uint16_t)data[0] << 8 | (uint16_t)data[1];
	uint16_t opt_len = (uint16_t)data[2] << 8 | (uint16_t)data[3];
	const uint8_t *opt_val = data + 4;
	
	coap_add_option(pdu, opt_num, opt_len, opt_val);

	coap_delete_pdu(pdu);
	
	return 0;
}
