# Multi-stage build for NEWS_System
FROM ubuntu:22.04 as builder

# Install build dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    g++ \
    libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy source code
COPY . .

# Build the application and tests
RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    make && \
    cd .. && \
    g++ -std=c++23 -Wall -o NEWS_System main.cpp ICU.cpp NEWSCalculator.cpp

# Runtime stage
FROM ubuntu:22.04

# Install runtime dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    libstdc++6 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy built artifacts from builder
COPY --from=builder /app/NEWS_System /app/NEWS_System
COPY --from=builder /app/build/run_tests /app/run_tests

# Make executables
RUN chmod +x /app/NEWS_System

# Run the main application
ENTRYPOINT ["/app/NEWS_System"]
