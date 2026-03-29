#!/bin/bash
set -e

cd "$(dirname "$0")"

DEB_PACKAGE="${1:-../pkg/trrspo_1.0-1_amd64.deb}"

if [ ! -f "$DEB_PACKAGE" ]; then
    echo "Error: Debian package not found at $DEB_PACKAGE"
    exit 1
fi

echo "Deploying $DEB_PACKAGE..."

# Install the .deb package
sudo dpkg -i "$DEB_PACKAGE"

# Build Docker image
DOCKER_IMAGE_NAME="${DOCKER_IMAGE_NAME:-trrspo}"
DOCKER_IMAGE_TAG="${DOCKER_IMAGE_TAG:-latest}"

docker build -t "$DOCKER_IMAGE_NAME:$DOCKER_IMAGE_TAG" -f Dockerfile ..

echo "Docker image built: $DOCKER_IMAGE_NAME:$DOCKER_IMAGE_TAG"

# Optional: Push to registry (uncomment if needed)
# docker push "$DOCKER_IMAGE_NAME:$DOCKER_IMAGE_TAG"

echo "Deployment complete!"
