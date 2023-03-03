{ lib, fetchFromGitHub, rustPlatform, libusb, pkg-config }:

rustPlatform.buildRustPackage rec {
  pname = "AnnePro2-Tools";
  version = "git";
  src = fetchFromGitHub {
    owner = "OpenAnnePro";
    repo = pname;
    rev = "fe5ed6585b0af274e3220d5abe49ee419c34924a";
    sha256 = "sha256-Oy5acTuE0Oz5CdFXDkwFrtoHEFC3B/lQR/4kjlqcibE=";
  };
  cargoHash = "sha256-MaweAHeLy7Q2jGf7ls3MSepKe+Cbaci3NjW07PIJhCw=";
  buildInputs = [ libusb ];
  nativeBuildInputs = [ pkg-config ];
}
