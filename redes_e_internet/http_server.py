from http.server import BaseHTTPRequestHandler, HTTPServer
html = """
<!DOCTYPE html>
<html lang="pt">
    <head>
        <title> TÍTULO LEGAL </title>
        <link rel="stylesheet" href="styles.css" />
        <script src="script.js"></script>
        <meta charset=utf-8>
    </head>
    <body>
        <h1>
            MINHA PÁGINA
        </h1>
        <p> ESSE É UM PARÁGRAFO muito LEGAL</p>
        <div>
            <form action="/" method="get">
                <label for="estudante"> Eres Estudante?</label>
                <input type="checkbox" id="estudante" name="estudante"> <br>
                Seu nome é: <input type="text" id="name" name="name">
                <input type="submit" value="Submit">
            </form>
        </div>
    </body>
</html>
"""
class MyHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        self.wfile.write(html.encode("utf8"))
server = HTTPServer(('localhost', 8000), MyHandler)
server.serve_forever()