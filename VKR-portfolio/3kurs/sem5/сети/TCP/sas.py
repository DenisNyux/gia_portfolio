import SocketServer
class TCPHandler(SocketServer.BaseRequestHandler):

   def handle(self):
     self.msg = self.request.recv(1024).strip()
     if self.msg == "on<EOF>":
       print "Turning On..."
     if self.msg == "off<EOF>":
       print "Turning Off..."



     if name == "main":
       host, port = '192.168.1.100', 1100



    server = SocketServer.TCPServer.TCPServer((host,port),TCPHandler)

    print "server is starting on", host, port


    server.serve_forever()

TCPHandler.handle()