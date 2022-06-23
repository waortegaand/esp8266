#define MAX_HTTP_RECV_BUFFER 512
#define MAX_HTTP_OUTPUT_BUFFER 2048

#ifndef __HTTP_REQUEST__
#define __HTTP_REQUEST__

void http_native_request(void);
void http_rest_with_hostname_path(void);
void http_rest_with_url(void);
//esp_err_t _http_event_handler(esp_http_client_event_t *evt);

#endif /* __HTTP_REQUEST__ */