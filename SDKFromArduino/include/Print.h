/*
  Print.h - Base class that provides print() and println()
  Copyright (c) 2008 David A. Mellis.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef Print_h
#define Print_h

#include <inttypes.h>
#include <stdio.h> // for size_t

#include "WString.h"
#include "Printable.h"
#include "Lightning.h"

#define DEC 10
#define HEX 16
#define OCT 8
#define BIN 2

class Print
{
  private:
    int write_error;
    size_t printNumber(unsigned long, uint8_t);
    size_t printFloat(double, uint8_t);
    void writeBufferToDebugOutput(const uint8_t *buffer, size_t size);
    void writeStringToDebugOutput(const char *str);
protected:
    bool write_debug_output;
    void setWriteError(int err = 1) { write_error = err; }
  public:
    Print() : write_error(0), write_debug_output(true) {}
  
    int getWriteError() { return write_error; }
    void clearWriteError() { setWriteError(0); }
  
    virtual size_t write(uint8_t) = 0;
    size_t write(const char *str) {
      if (str == NULL) return 0;
      if (write_debug_output)
          writeStringToDebugOutput(str);
      return write((const uint8_t *)str, strlen(str));
    }
    virtual size_t write(const uint8_t *buffer, size_t size);
    size_t write(const char *buffer, size_t size) {
        if (write_debug_output)
            writeBufferToDebugOutput((const uint8_t *)buffer, size);
        return write((const uint8_t *)buffer, size);
    }

    void enablePrintDebugOutput(bool isEnabled) {
        write_debug_output = isEnabled;
    }

    LIGHTNING_DLL_API size_t print(const __FlashStringHelper *);
    LIGHTNING_DLL_API size_t print(const String &);
    LIGHTNING_DLL_API size_t print(const char[]);
    LIGHTNING_DLL_API size_t print(char);
    LIGHTNING_DLL_API size_t print(unsigned char, int = DEC);
    LIGHTNING_DLL_API size_t print(int, int = DEC);
    LIGHTNING_DLL_API size_t print(unsigned int, int = DEC);
    LIGHTNING_DLL_API size_t print(long, int = DEC);
    LIGHTNING_DLL_API size_t print(unsigned long, int = DEC);
    LIGHTNING_DLL_API size_t print(double, int = 2);
    LIGHTNING_DLL_API size_t print(const Printable&);

    LIGHTNING_DLL_API size_t println(const __FlashStringHelper *);
    LIGHTNING_DLL_API size_t println(const String &s);
    LIGHTNING_DLL_API size_t println(const char[]);
    LIGHTNING_DLL_API size_t println(char);
    LIGHTNING_DLL_API size_t println(unsigned char, int = DEC);
    LIGHTNING_DLL_API size_t println(int, int = DEC);
    LIGHTNING_DLL_API size_t println(unsigned int, int = DEC);
    LIGHTNING_DLL_API size_t println(long, int = DEC);
    LIGHTNING_DLL_API size_t println(unsigned long, int = DEC);
    LIGHTNING_DLL_API size_t println(double, int = 2);
    LIGHTNING_DLL_API size_t println(const Printable&);
    LIGHTNING_DLL_API size_t println(void);
};

#endif
