#!/bin/bash

commit_hash=$(git log --pretty=format:'%h' -n 1)
git archive --format=tar --prefix="${commit_hash}"/ HEAD | gzip >"${commit_hash}".tar.gz
echo "${commit_hash}".tar.gz