with import <nixpkgs> {};

stdenv.mkDerivation {
  name = "rgla-dev";
  buildInputs = [ cmake glfw glbinding glm ];
}
