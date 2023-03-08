#include <coap3/coap.h>

#define COAP_MAX_PDU_SIZE 1152
#define COAP_OPT_NUM 25

static const coap_option_num_t coap_options[COAP_OPT_NUM] = {
	COAP_OPTION_IF_MATCH,
	COAP_OPTION_URI_HOST,
	COAP_OPTION_ETAG,
	COAP_OPTION_IF_NONE_MATCH,
	COAP_OPTION_OBSERVE,
	COAP_OPTION_URI_PORT,
	COAP_OPTION_LOCATION_PATH,
	COAP_OPTION_OSCORE,
	COAP_OPTION_URI_PATH,
	COAP_OPTION_CONTENT_FORMAT,
	COAP_OPTION_CONTENT_TYPE,
	COAP_OPTION_MAXAGE,
	COAP_OPTION_URI_QUERY,
	COAP_OPTION_HOP_LIMIT,
	COAP_OPTION_ACCEPT,
	COAP_OPTION_LOCATION_QUERY,
	COAP_OPTION_BLOCK2,
	COAP_OPTION_BLOCK1,
	COAP_OPTION_SIZE2,
	COAP_OPTION_PROXY_URI,
	COAP_OPTION_PROXY_SCHEME,
	COAP_OPTION_SIZE1,
	COAP_OPTION_ECHO,
	COAP_OPTION_NORESPONSE,
	COAP_OPTION_RTAG
};

static const uint16_t coap_option_max_length[COAP_OPT_NUM] = {
	8,
	255,
	8,
	1, // 0
	3,
	2,
	255,
	255,
	255,
	2,
	2,
	4,
	255,
	1,
	2,
	255,
	3,
	3,
	4,
	1034,
	255,
	4,
	40,
	1,
	8
};

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {	
	if (size < 4) {
		return 0;
	}

	uint16_t rand_opt_idx = ((uint16_t)(data[1]<<8) | data[0]);
	int opt_idx = (int)(rand_opt_idx % COAP_OPT_NUM);
	coap_option_num_t opt = coap_options[opt_idx];
	uint16_t max_opt_len = coap_option_max_length[opt_idx];
	uint16_t rand_opt_len = ((uint16_t)(data[3]<<8) | data[2]);
	int opt_len = (int)(rand_opt_len % max_opt_len);
	printf("opt_idx: %d ", opt_idx);
	printf("opt_len: %d\n", opt_len);
	if (size-4 < (size_t)opt_len) {
		return 0;
	}

	coap_pdu_t *pdu = coap_pdu_init(COAP_MESSAGE_CON, COAP_REQUEST_GET, 0, COAP_MAX_PDU_SIZE);

	if (pdu == NULL) {
		return 0;
	}

	//coap_add_option(pdu, opt, opt_len, data+4);
	coap_add_option(pdu, opt, size-4, data+4);

	coap_delete_pdu(pdu);
	
	return 0;
}
