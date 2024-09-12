# CMakeList.txt: проект CMake для CMakeRacing; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CMakeRacing")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(Transports SHARED EXCLUDE_FROM_ALL "transports/Transport.h" "transports/Transport.cpp" "transports/landingTransports/LandingTransport.h" "transports/landingTransports/LandingTransport.cpp" "transports/landingTransports/camel/Camel.h" "transports/landingTransports/camel/Camel.cpp" "transports/landingTransports/centaur/Centaur.h" "transports/landingTransports/centaur/Centaur.cpp" "transports/landingTransports/crossoverShoes/CrossoverShoes.h" "transports/landingTransports/crossoverShoes/CrossoverShoes.cpp" "transports/landingTransports/fastCamel/FastCamel.h" "transports/landingTransports/fastCamel/FastCamel.cpp" "transports/flyingTransports/FlyingTransport.h" "transports/flyingTransports/FlyingTransport.cpp" "transports/flyingTransports/broomstick/Broomstick.h" "transports/flyingTransports/broomstick/Broomstick.cpp" "transports/flyingTransports/eagle/Eagle.h" "transports/flyingTransports/eagle/Eagle.cpp" "transports/flyingTransports/magicCarpet/MagicCarpet.h" "transports/flyingTransports/magicCarpet/MagicCarpet.cpp" "transports/TransportCollection.h")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeRacing "CMakeRacing.h" "CMakeRacing.cpp" "RacingType.h" "TransportList.h" "Functions.h" "Functions.cpp")

target_link_libraries(CMakeRacing Transports)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeRacing PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
