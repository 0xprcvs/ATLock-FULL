#include "RFIDManager.h"

RFIDManager RFID;

// =====================================================
// Initialize
// =====================================================

void RFIDManager::begin()
{
}

// =====================================================
// Update
// =====================================================

void RFIDManager::update()
{
    cardAvailable = false;
}

// =====================================================
// Card Available?
// =====================================================

bool RFIDManager::available()
{
    return cardAvailable;
}

// =====================================================
// Read UID
// =====================================================

String RFIDManager::readUID()
{
    cardAvailable = false;

    return uid;
}