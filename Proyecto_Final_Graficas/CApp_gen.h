#pragma once
#include "CApp.h"
#include <windows.h>

class CApp_gen: public CApp
{
public:
  CApp_gen();
  ~CApp_gen();

  bool Init();
  bool InitWindow();
  int run();
  static LRESULT CALLBACK WndProc(HWND window, UINT message, WPARAM wParam, LPARAM lParam);
 
};

