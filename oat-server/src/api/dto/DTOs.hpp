#ifndef DTOs_hpp 
#define DTOs_hpp 

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class BasicDTO : public oatpp::DTO {
    DTO_INIT(BasicDTO, DTO)
    DTO_FIELD(Int32, statusCode);
    DTO_FIELD(String, message);
}; 

#include OATPP_CODEGEN_END(DTO)

#endif /* DTOs_hpp */