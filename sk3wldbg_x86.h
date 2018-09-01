/*
   Source for Sk3wlDbg IdaPro plugin
   Copyright (c) 2016 Chris Eagle

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 2 of the License, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
   more details.

   You should have received a copy of the GNU General Public License along with
   this program; if not, write to the Free Software Foundation, Inc., 59 Temple
   Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include "sk3wldbg.h"

struct sk3wldbg_x86_16 : public sk3wldbg {
   sk3wldbg_x86_16();
   bool save_ret_addr(uint64_t retaddr);
   bool call_changes_sp() {return true;};
};

struct sk3wldbg_x86_32 : public sk3wldbg {
   sk3wldbg_x86_32();   
   bool save_ret_addr(uint64_t retaddr);
   bool call_changes_sp() {return true;};
   virtual bool is_system_call(uint8_t *inst, uint32_t size);
   virtual void handle_system_call(uint8_t *inst, uint32_t size);
};

struct sk3wldbg_x86_64 : public sk3wldbg {
   sk3wldbg_x86_64();
   bool save_ret_addr(uint64_t retaddr);
   bool call_changes_sp() {return true;};
};
