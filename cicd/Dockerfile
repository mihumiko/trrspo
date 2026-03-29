FROM debian:bullseye-slim

RUN apt-get update && apt-get install -y --no-install-recommends \
    g++ \
    make \
    libc6 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY src/ /app/src/

RUN cd src && make && cp bubblesort /usr/bin/bubblesort

ENTRYPOINT ["/usr/bin/bubblesort"]
