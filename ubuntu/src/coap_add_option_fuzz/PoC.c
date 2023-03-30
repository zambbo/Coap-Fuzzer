#include <coap3/coap.h>

int main() {	
	const uint8_t data[4] = {10, 129, 10, 129};
	
	coap_pdu_t *pdu = coap_pdu_init(COAP_MESSAGE_CON, COAP_REQUEST_GET, 0, COAP_MAX_PDU_SIZE);

	if (pdu == NULL) {
		return 0;
	}
	coap_add_option(pdu, COAP_OPTION_URI_PORT, 8, data);

	coap_delete_pdu(pdu);
	
	return 0;
}
