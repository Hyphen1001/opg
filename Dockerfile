FROM gcc:10
WORKDIR /app/
COPY ./* ./
RUN gcc my-program.cpp -o program
RUN chmod +x program
