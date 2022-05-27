FROM ubuntu:21.04
LABEL Autor="Nyukhalov Denis <denisn2000@gmail.com>"
RUN apt update
RUN apt install -y nginx
RUN rm -rf /var/www/html
COPY html_to_docker.html /var/www/html
CMD ["nginx", "-g", "daemon off;"]
EXPOSE 80
