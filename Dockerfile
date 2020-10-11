FROM gcc:10
WORKDIR /app/
COPY ./* ./
RUN g++ my-program.cpp -o program
RUN chmod +x program
