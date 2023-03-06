#include <coap3/coap.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
	if (size < 4) return 0;

	coap_pdu_type_t type = (coap_pdu_type_t)(data[0] % 4);
	coap_pdu_code_t code = (coap_pdu_code_t)(data[1] % 256);
	coap_mid_t mid = (data[2] << 8) | data[3];

	coap_pdu_t *pdu = coap_pdu_init(type, code, mid, size);

	coap_add_data(pdu, size-4, data + 4);

	coap_delete_pdu(pdu);

	return 0;	
}
