##
## Development
##

APP_NAME=disco-ps-core

oats:
		@echo "Building oat server..."
		mkdir -p build && \
		  	cd build && \
		  	cmake .. && \
		  	$(MAKE) --no-print-directory && \
		  	./$(APP_NAME)

dock-build:
		@echo "Building docker image..."
		docker build -t $(APP_NAME) . 

dock-run:
		@echo "Running docker container..."
		docker run -it --rm -p 4040:4040 --name="$(APP_NAME)" $(APP_NAME) 

dock-stop:
		@echo "Stopping docker container..."
		docker stop $(APP_NAME)
		docker rm $(APP_NAME)

dock-up:
		$(MAKE) dock-build
		$(MAKE) dock-run