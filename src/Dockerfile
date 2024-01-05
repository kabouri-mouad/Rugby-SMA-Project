# Use an official base image with a specific version of SFML
FROM alpine:3.14

# Set the working directory in the container
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY ../ /app

# Install any dependencies needed for your application
# Install necessary dependencies, including make
RUN apk update && \
    apk add --no-cache g++ make sfml-dev

# Build the C++ application
RUN make

# Expose any ports the app is expecting
# For example, if your C++ application is listening on port 8080, you can expose it here.
EXPOSE 8080

# Define the command to run your application
CMD ["./main"]
