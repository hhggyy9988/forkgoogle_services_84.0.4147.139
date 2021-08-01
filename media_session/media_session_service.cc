// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "services/media_session/media_session_service.h"

#include "base/bind.h"
#include "services/media_session/audio_focus_manager.h"

namespace media_session {

MediaSessionService::MediaSessionService(
    mojo::PendingReceiver<mojom::MediaSessionService> receiver)
    : receiver_(this, std::move(receiver)),
      audio_focus_manager_(std::make_unique<AudioFocusManager>()) {}

MediaSessionService::~MediaSessionService() = default;

void MediaSessionService::BindAudioFocusManager(
    mojo::PendingReceiver<mojom::AudioFocusManager> receiver) {
  audio_focus_manager_->BindToInterface(std::move(receiver));
}

void MediaSessionService::BindAudioFocusManagerDebug(
    mojo::PendingReceiver<mojom::AudioFocusManagerDebug> receiver) {
  audio_focus_manager_->BindToDebugInterface(std::move(receiver));
}

void MediaSessionService::BindMediaControllerManager(
    mojo::PendingReceiver<mojom::MediaControllerManager> receiver) {
  audio_focus_manager_->BindToControllerManagerInterface(std::move(receiver));
}

}  // namespace media_session
