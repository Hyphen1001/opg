FROM gcc:10
WORKDIR /app/
COPY ./* ./
RUN gcc problem1.cpp -o problem1
RUN chmod +x program
