#include <coap3/coap.h>

#define COAP_MAX_PDU_SIZE 1152


int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
	if (size < 2) return 0;

	uint8_t proxy_or_plain = data[1] % 2;
	

	coap_pdu_t *pdu = coap_pdu_init(COAP_MESSAGE_CON, COAP_REQUEST_GET, 0, COAP_MAX_PDU_SIZE);
	
	if (pdu == NULL) return 0;

		

	if (proxy_or_plain == 0) {
		coap_add_option(pdu, COAP_OPTION_PROXY_URI, size-1, data+1);	
	}
	else {
		coap_add_option(pdu, COAP_OPTION_URI_PATH, size-1, data+1);
	}

	coap_string_t *uri = coap_get_uri_path(pdu);

	if (uri) {
		coap_delete_string(uri);
	}

	coap_delete_pdu(pdu);

	return 0;
}
