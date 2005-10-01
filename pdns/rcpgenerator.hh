/*
    PowerDNS Versatile Database Driven Nameserver
    Copyright (C) 2005  PowerDNS.COM BV

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2 as 
    published by the Free Software Foundation

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/


#ifndef PDNS_RCPGENERATOR_HH
#define PDNS_RCPGENERATOR_HH

#include <string>
#include <stdexcept>

using namespace std;

class RecordTextException : public runtime_error
{
public:
  RecordTextException(const string& str) : runtime_error(str)
  {}
};

class RecordTextReader
{
public:
  RecordTextReader(const string& str, const string& zone="");
  void xfrInt(unsigned int& val);
  void xfrLabel(string& val);
  void xfrQuotedText(string& val);

private:
  string d_string;
  string d_zone;
  string::size_type d_pos;
  string::size_type d_end;
  void skipSpaces();
};

class RecordTextWriter
{
public:
  RecordTextWriter(string& str);
  void xfrInt(const unsigned int& val);
  void xfrLabel(const string& val);
  void xfrQuotedText(const string& val);

private:
  string& d_string;
};


#endif
