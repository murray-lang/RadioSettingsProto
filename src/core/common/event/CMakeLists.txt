cmake_minimum_required(VERSION 4.1)

project(core-common-event)

set(DATA_EVENT_FILES

        ${CMAKE_CURRENT_LIST_DIR}/include/event/DataEventBaseT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/event/EventTarget.h

        ${CMAKE_CURRENT_LIST_DIR}/include/event/sample/AudioEventData.h
        ${CMAKE_CURRENT_LIST_DIR}/include/event/sample/RxAudioEventT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/event/sample/TxAudioEventT.h

        ${CMAKE_CURRENT_LIST_DIR}/include/event/sample/IqEventData.h
        ${CMAKE_CURRENT_LIST_DIR}/include/event/sample/RxIqEventT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/event/sample/TxIqEventT.h

        ${CMAKE_CURRENT_LIST_DIR}/include/event/metering/RxIqMeterEventData.h
        ${CMAKE_CURRENT_LIST_DIR}/include/event/metering/RxIqMeterEventT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/event/metering/RxMeterEventData.h
        ${CMAKE_CURRENT_LIST_DIR}/include/event/metering/RxMeterEventT.h
)

add_library(core-common-event INTERFACE ${DATA_EVENT_FILES})

target_include_directories(core-common-event INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(core-common-event INTERFACE
        core-common-samples
)
