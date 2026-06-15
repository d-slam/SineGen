/*
  ==============================================================================

    AudioState.h
    Created: 15 Jun 2026 11:06:51pm
    Author:  Dami

  ==============================================================================
*/

#pragma once

#include <atomic>

struct AudioState
{
    std::atomic<float> level{ 0.1f };
    std::atomic<double> freq{ 500.0f };

};