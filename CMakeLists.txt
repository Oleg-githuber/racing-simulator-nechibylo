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

set(TRANSPORTFILES "transports/Transport.h" "transports/Transport.cpp")
set(LANDINGFILES "transports/landingTransports/LandingTransport.h" "transports/landingTransports/LandingTransport.cpp")
set(CAMELFILES "transports/landingTransports/camel/Camel.h" "transports/landingTransports/camel/Camel.cpp")
set(CENTAURFILES "transports/landingTransports/centaur/Centaur.h" "transports/landingTransports/centaur/Centaur.cpp")
set(SHUESFILES "transports/landingTransports/crossoverShoes/CrossoverShoes.h" "transports/landingTransports/crossoverShoes/CrossoverShoes.cpp")
set(FASTCAMELFILES "transports/landingTransports/fastCamel/FastCamel.h" "transports/landingTransports/fastCamel/FastCamel.cpp")
set(LFLYINGFILES "transports/flyingTransports/FlyingTransport.h" "transports/flyingTransports/FlyingTransport.cpp")
set(BROOMFILES "transports/flyingTransports/broomstick/Broomstick.h" "transports/flyingTransports/broomstick/Broomstick.cpp")
set(EAGLEFILES "transports/flyingTransports/eagle/Eagle.h" "transports/flyingTransports/eagle/Eagle.cpp")
set(CARPETFILES "transports/flyingTransports/magicCarpet/MagicCarpet.h" "transports/flyingTransports/magicCarpet/MagicCarpet.cpp")
set(MAINFILE "transports/TransportCollection.h")


add_library(Transports SHARED ${TRANSPORTFILES} ${LANDINGFILES} ${CAMELFILES} ${CENTAURFILES} ${SHUESFILES} ${FASTCAMELFILES} ${LFLYINGFILES} ${BROOMFILES} ${EAGLEFILES} ${CARPETFILES} ${MAINFILE})

# Добавьте источник в исполняемый файл этого проекта.

set(HEADERS "CMakeRacing.h""RacingType.h" "TransportList.h" "Functions.h")

set(SOURCES "CMakeRacing.cpp" "Functions.cpp")

set(PROJECTNAME CMakeRacing)

add_executable (${PROJECTNAME} ${HEADERS} ${SOURCES})

target_link_libraries(CMakeRacing Transports)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeRacing PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
