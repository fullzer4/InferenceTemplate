FROM gcc:latest as builder

WORKDIR /app

COPY main.c .

RUN gcc -o programa main.c

FROM debian:bullseye-slim

WORKDIR /app

COPY --from=builder /app/programa .

CMD ["./server_inference"]