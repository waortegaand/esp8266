# Embed the server root certificate into the final binary
#
# (If this was a component, we would set COMPONENT_EMBED_TXTFILES here.)
idf_component_register(SRCS "http_client_main.c"
                    INCLUDE_DIRS "include"
                    EMBED_TXTFILES certs/iiot4_herokuapp_com_chain.pem)
