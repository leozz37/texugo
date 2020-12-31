# Including CPM
include(${CPM_DOWNLOAD_LOCATION})

# Catch2
CPMAddPackage(
    NAME Catch2
    GITHUB_REPOSITORY catchorg/Catch2
    VERSION 2.5.0)

add_subdirectory(config)
