#include <coap3/coap.h>



extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
	coap_pdu_t *pdu = coap_pdu_init(0, 0, 0, size);
	if (!pdu) {
		return 0;
	}
	
	int ret = coap_pdu_parse(COAP_PROTO_UDP, (uint8_t *)data, size, pdu);
	if (ret < 0) {
		coap_delete_pdu(pdu);
		return 0;
	}

	coap_address_t dst;
	coap_address_init(&dst);
	dst.addr.sa.sa_family = AF_INET;
	dst.addr.sin.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	dst.addr.sin.sin_port = htons(COAP_DEFAULT_PORT);

	coap_context_t *ctx = coap_new_context(NULL);
	if (!ctx) {
		coap_delete_pdu(pdu);	
		return 0;
	}

	coap_session_t *session = coap_new_client_session(ctx, NULL, &dst, COAP_PROTO_UDP);
	if (!session) {
		coap_delete_pdu(pdu);
		coap_free_context(ctx);
		return 0;
	}

	coap_send(session, pdu);

	coap_session_release(session);
	coap_free_context(ctx);
	
	return 0;	
}
