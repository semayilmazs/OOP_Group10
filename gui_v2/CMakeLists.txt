cmake_minimum_required(VERSION 3.16)

project(application VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)  # Automatically process .ui files
set(CMAKE_AUTOMOC ON)  # Automatically process Qt's moc
set(CMAKE_AUTORCC ON)  # Automatically process Qt's resource files

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt libraries (Widgets in this case)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Specify your source files and UI files
set(PROJECT_SOURCES
    main.cpp
    Customer.h
    Customer.cpp
    User.h
    User.cpp
    customer.txt
    login.h             # Add login.h
    login.cpp           # Add login.cpp
    login.ui            # Add login.ui
    mainwindow.h        # Add main window header files
    mainwindow.cpp      # Add main window source files
    mainwindow.ui       # Add main window UI files
    Product.h           
    Product.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(application
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(application SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(application
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link Qt libraries to your project
target_link_libraries(application PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Bundle settings for macOS (if needed)
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.application)
endif()
set_target_properties(application PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Install settings
include(GNUInstallDirs)
install(TARGETS application
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finalization for Qt6 (if using Qt6)
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(application)
endif()
