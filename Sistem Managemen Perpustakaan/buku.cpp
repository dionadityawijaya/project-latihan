#include "buku.h"
#include <string>

Buku::Buku(int i, const std::string& j, const std::string p, bool t) : id(i), judul(j), penulis(p), tersedia(t) {}