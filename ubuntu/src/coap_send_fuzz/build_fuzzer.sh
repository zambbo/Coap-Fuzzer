clang -fsanitize=fuzzer,address -I/home/libcoap/include -L/home/libcoap/.libs -lcoap-3 -o coap_send_fuzz 
