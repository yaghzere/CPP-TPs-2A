Dernière question :

    Il est nécessaire de caster "void" avec string(). En effet, "void" est de type const char*, donc singleton("void") est de type Set<const char*> alors que
    dictionary, de type Set<string>, est plus précisement de type Set<std::__cxx11::basic_string<char>>, autrement dit, le type string est dérive du modèle basic_string
    appliqué sur le type char.
    
    
Critique de notre rendu :

	On n'a pas pu écrire la fonction image comme c'est bien demandé.
