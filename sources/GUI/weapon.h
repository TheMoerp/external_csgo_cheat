#pragma once
#include <iostream>
#include "memory.h"
#include "structures.h"
#include "config.h"


Item GetItemByID(int itemID);

int GetKnifeItemDefinitionID(int knifeID);

void LoadSkinConfig();
