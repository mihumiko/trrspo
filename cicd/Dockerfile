FROM debian:bullseye-slim

RUN apt-get update && apt-get install -y --no-install-recommends \
    libc6 \
    && rm -rf /var/lib/apt/lists/*

COPY usr/bin/bubblesort /usr/bin/bubblesort
RUN chmod +x /usr/bin/bubblesort

ENTRYPOINT ["/usr/bin/bubblesort"]
