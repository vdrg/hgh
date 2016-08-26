FROM ubuntu:14.04

RUN apt-get update && apt-get install -y \
      pkg-config gettext zlib1g-dev libffi-dev \
      autoconf automake build-essential libtool libxml2-utils \
      libfcgi-dev shared-mime-info libglib2.0-dev wget peg ca-certificates \
      --no-install-recommends && apt-get clean

RUN mkdir -p /usr/src/app
WORKDIR /usr/src/app

# Bundle app source
COPY . /usr/src/app

RUN cd /usr/src/app/balde && \
      ./autogen.sh && \
      ./configure --prefix=/usr && \
      make && \
      make install

RUN cd /usr/src/app && \
      ./autogen.sh && \
      ./configure && \
      make && \
      touch database.db

EXPOSE 8080

CMD [ "./hgh", "-s" ]
