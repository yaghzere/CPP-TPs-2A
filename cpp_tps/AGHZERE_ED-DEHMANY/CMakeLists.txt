

# Chemin  répertoires contenant les fichiers entêtes.
INCLUDE_DIRECTORIES( ./ )

# Chemin du répertoire contenant les binaires.
SET ( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

# Option du compilateur pour supporter C++ 2011.
SET( CMAKE_CXX_FLAGS "-std=c++11 -Wall")

# Création des exécutables.
ADD_EXECUTABLE( set_test ./set_test.cpp)