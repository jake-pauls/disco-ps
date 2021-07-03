#ifndef AppController_hpp
#define AppController_hpp

#include "../dto/DTOs.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) 

class AppController : public oatpp::web::server::api::ApiController {
protected:
    AppController(const std::shared_ptr<ObjectMapper> &objectMapper)
    : oatpp::web::server::api::ApiController(objectMapper)
    {}
public:
    /**
     * Inject @objectMapper component as default parameter
     */
    static std::shared_ptr<AppController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::shared_ptr<AppController>(new AppController(objectMapper));
    }
public:
    /**
     * Test API Endpoints
     * Async endpoints must contain a coroutine entrypoint returning an Action
     * Similar effect to async with 'Result' (Rust) or 'Promise' (JS)
     */ 
    ENDPOINT_ASYNC("GET", "/", root) {
        ENDPOINT_ASYNC_INIT(root);

        Action act() override {
            auto dto = BasicDTO::createShared();
            dto->message = "There's nothing to see here, although what is here is async.";
            dto->statusCode = 200;
            return _return(controller->createDtoResponse(Status::CODE_200, dto));
        }
    };

    ENDPOINT_ASYNC("GET", "/ping", ping) {
        ENDPOINT_ASYNC_INIT(ping);

        Action act() override {
            auto dto = BasicDTO::createShared();
            dto->statusCode = 200;
            dto->message = "Pong!";
            return _return(controller->createDtoResponse(Status::CODE_200, dto));
        }
    };
};

#include OATPP_CODEGEN_END(ApiController) 

#endif /* AppController_hpp */