#!/bin/bash
set -e

cd "$(dirname "$0")"

DEB_PACKAGE="${1:-../pkg/trrspo_1.0-1_amd64.deb}"

if [ ! -f "$DEB_PACKAGE" ]; then
    echo "Error: Debian package not found at $DEB_PACKAGE"
    exit 1
fi

sudo dpkg -i "$DEB_PACKAGE"

DOCKER_IMAGE_NAME="${DOCKER_IMAGE_NAME:-trrspo}"
DOCKER_IMAGE_TAG="${DOCKER_IMAGE_TAG:-latest}"

docker build -t "$DOCKER_IMAGE_NAME:$DOCKER_IMAGE_TAG" -f Dockerfile ..

