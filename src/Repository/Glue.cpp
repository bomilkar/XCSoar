// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The XCSoar Project

#include "Glue.hpp"
#include "net/http/DownloadManager.hpp"
#include "util/StaticString.hxx"
#include "system/Path.hpp"

#include <tchar.h>

#define REPOSITORY_URI "http://download.xcsoar.org/repository"

static bool repository_downloaded = false;

void
EnqueueRepositoryDownload(bool force)
{
  if (repository_downloaded && !force)
    return;

  const char default_repo[] = "http://xcs.fliegerclub-moosburg.de/share/repository";
  const char *repository = getenv("REPOSITORY_URI");
  if ((repository == NULL) || (StringLength(repository) < 5)) repository = default_repo;

  repository_downloaded = true;
  Net::DownloadManager::Enqueue(repository, Path(_T("repository")));
}
