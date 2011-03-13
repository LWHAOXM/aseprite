/* ASE - Allegro Sprite Editor
 * Copyright (C) 2001-2011  David Capello
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef DOCUMENTS_H_INCLUDED
#define DOCUMENTS_H_INCLUDED

#include "base/disable_copying.h"

#include <vector>

class Sprite;

class Documents
{
public:
  typedef std::vector<Sprite*>::iterator iterator;
  typedef std::vector<Sprite*>::const_iterator const_iterator;

  Documents();
  ~Documents();

  iterator begin() { return m_documents.begin(); }
  iterator end() { return m_documents.end(); }
  const_iterator begin() const { return m_documents.begin(); }
  const_iterator end() const { return m_documents.end(); }

  int size() const { return m_documents.size(); }
  bool empty() const { return m_documents.empty(); }

  // Adds a new document to the list. If the destructor is called the
  // document is deleted automatically.
  void addDocument(Sprite* sprite);

  // Removes a document from the list without deleting it. You must to
  // delete the document after removing it.
  void removeDocument(Sprite* sprite);

  // Moves the document to the given location in the same
  // list. E.g. It is used to reorder documents when they are selected
  // as active.
  void moveDocument(Sprite* sprite, int index);

  // Deletes all documents in the list (calling "delete" operation).
  void deleteAll();
 
  Sprite* getByIndex(int index) const { return m_documents[index]; }

private:
  std::vector<Sprite*> m_documents;

  DISABLE_COPYING(Documents)
};

#endif
