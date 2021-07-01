#ifndef AppController_hpp
#define AppController_hpp

#include "../dto/DTOs.hpp"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController) 

class AppController : public oatpp::web::server::api::ApiController {
public:
    /**
     * Constructor/Object Mapper
     * @param objectMapper - default object mapper used to serialize/deserialize API DTO's 
     */
    AppController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper)
    {}

public:
    /**
     * API Endpoints
     */ 
    ENDPOINT("GET", "/", root) {
        auto dto = AppDto::createShared();
        dto->statusCode = 200;
        dto->message = "Ping, Pong!";
        return createDtoResponse(Status::CODE_200, dto);
    }
};

#include OATPP_CODEGEN_END(ApiController) 

#endif /* AppController_hpp */