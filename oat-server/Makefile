##
## Development
##

oats:
		@echo "Building oat server..."
				mkdir -p build && \
						cd build && \
						cmake .. && \
						$(MAKE) --no-print-directory && \
						./disco-ps-core

dock-oats:
		@echo "Building docker image..."
		docker build --tag disco-ps-core . 
		docker run --publish 4040:4040 disco-ps-core

