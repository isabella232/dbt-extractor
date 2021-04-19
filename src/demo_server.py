import compiler
from http.server import BaseHTTPRequestHandler, HTTPServer
import json
import logging

class Handler(BaseHTTPRequestHandler):
    def _set_response(self, body):
        self.send_response(200)
        self.send_header('Content-type', 'application/json')
        self.end_headers()
        self.wfile.write(json.dumps(body).encode(encoding='utf_8'))

    def do_POST(self):
        content_length = int(self.headers['Content-Length']) # <--- Gets the size of data
        post_data = self.rfile.read(content_length) # <--- Gets the data itself
        res = compiler.extract_from_source(compiler.get_parser(), post_data.decode('utf-8'))
        res = json_friendly(res)

        logging.info(f"\nPOST:     {post_data.decode('utf-8')}\nResponse: {res}\n")

        self._set_response(res)

def run(server_class, handler_class, port):
    logging.basicConfig(level=logging.INFO)
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    logging.info('Starting httpd...\n')
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        pass
    httpd.server_close()
    logging.info('Stopping httpd...\n')

def json_friendly(compiler_output):
    json_friendly = dict(compiler_output)
    json_friendly['sources'] = list(json_friendly['sources'])
    return json_friendly

if __name__ == '__main__':
    run(HTTPServer, Handler, 8000)