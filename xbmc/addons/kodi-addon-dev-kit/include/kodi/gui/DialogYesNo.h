#pragma once
/*
 *      Copyright (C) 2005-2017 Team KODI
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with KODI; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "definitions.h"
#include "../AddonBase.h"

namespace kodi
{
namespace gui
{

  //============================================================================
  ///
  /// \defgroup cpp_kodi_gui_DialogYesNo Dialog Yes/No
  /// \ingroup cpp_kodi_gui
  /// @{
  /// @brief \cpp_namespace{ kodi::gui::DialogYesNo }
  /// **Yes / No dialog**
  ///
  /// The Yes / No dialog can be used to inform the user about questions and get
  /// the answer.
  ///
  /// In order to achieve a line break is a <b>\\n</b> directly in the text or
  /// in the <em>"./resources/language/resource.language.??_??/strings.po"</em>
  /// to call with <b>std::string kodi::general::GetLocalizedString(...);</b>.
  ///
  /// These are pure static functions them no other initialization need.
  ///
  /// It has the header \ref DialogYesNo.h "#include <kodi/gui/DialogYesNo.h>"
  /// be included to enjoy it.
  ///
  ///
  namespace DialogYesNo
  {
    //==========================================================================
    ///
    /// \ingroup cpp_kodi_gui_DialogYesNo
    /// @brief Use dialog to get numeric new password with one text string shown
    /// everywhere and cancel return field
    ///
    /// @param[in] heading    Dialog heading
    /// @param[in] text       Multi-line text
    /// @param[out] canceled  Return value about cancel button
    /// @param[in] noLabel    [opt] label to put on the no button
    /// @param[in] yesLabel   [opt] label to put on the yes button
    /// @return           Returns True if 'Yes' was pressed, else False
    ///
    /// @note It is preferred to only use this as it is actually a multi-line text.
    ///
    ///
    ///-------------------------------------------------------------------------
    ///
    /// **Example:**
    /// ~~~~~~~~~~~~~{.cpp}
    /// #include <kodi/gui/DialogYesNo.h>
    ///
    /// bool canceled;
    /// bool ret = kodi::gui::DialogYesNo::ShowAndGetInput(
    ///    "Yes / No test call",   /* The Header */
    ///    "You has opened Yes / No dialog for test\n\nIs this OK for you?",
    ///    canceled,               /* return value about cancel button */
    ///    "Not really",           /* No label, is optional and if empty "No" */
    ///    "Ohhh yes");            /* Yes label, also optional and if empty "Yes" */
    /// fprintf(stderr, "You has called Yes/No, returned '%s' and was %s\n",
    ///          ret ? "yes" : "no",
    ///          canceled ? "canceled" : "not canceled");
    /// ~~~~~~~~~~~~~
    ///
    inline bool ShowAndGetInput(
      const std::string& heading,
      const std::string& text,
      bool& canceled,
      const std::string& noLabel = "",
      const std::string& yesLabel = "")
    {
      return ::kodi::addon::CAddonBase::m_interface->toKodi.kodi_gui->dialogYesNo.ShowAndGetInputSingleText(::kodi::addon::CAddonBase::m_interface->toKodi.kodiBase, heading.c_str(), text.c_str(), canceled, noLabel.c_str(), yesLabel.c_str());
    }
    //--------------------------------------------------------------------------

    //==========================================================================
    ///
    /// \ingroup cpp_kodi_gui_DialogYesNo
    /// @brief Use dialog to get numeric new password with separated line strings
    ///
    /// @param[in] heading      Dialog heading
    /// @param[in] line0        Line #0 text
    /// @param[in] line1        Line #1 text
    /// @param[in] line2        Line #2 text
    /// @param[in] noLabel      [opt] label to put on the no button.
    /// @param[in] yesLabel     [opt] label to put on the yes button.
    /// @return                 Returns True if 'Yes' was pressed, else False.
    ///
    ///
    ///-------------------------------------------------------------------------
    ///
    /// **Example:**
    /// ~~~~~~~~~~~~~{.cpp}
    /// #include <kodi/gui/DialogYesNo.h>
    ///
    /// bool ret = kodi::gui::DialogYesNo::ShowAndGetInput(
    ///    "Yes / No test call",   // The Header
    ///    "You has opened Yes / No dialog for test",
    ///    "",
    ///    "Is this OK for you?",
    ///    "Not really",           // No label, is optional and if empty "No"
    ///    "Ohhh yes");            // Yes label, also optional and if empty "Yes"
    /// fprintf(stderr, "You has called Yes/No, returned '%s'\n",
    ///          ret ? "yes" : "no");
    /// ~~~~~~~~~~~~~
    ///
    inline bool ShowAndGetInput(
      const std::string&      heading,
      const std::string&      line0,
      const std::string&      line1,
      const std::string&      line2,
      const std::string&      noLabel = "",
      const std::string&      yesLabel = "")
    {
      return ::kodi::addon::CAddonBase::m_interface->toKodi.kodi_gui->dialogYesNo.ShowAndGetInputLineText(::kodi::addon::CAddonBase::m_interface->toKodi.kodiBase, heading.c_str(), line0.c_str(), line1.c_str(), line2.c_str(), noLabel.c_str(), yesLabel.c_str());
    }
    //--------------------------------------------------------------------------

    //==========================================================================
    ///
    /// \ingroup cpp_kodi_gui_DialogYesNo
    /// @brief Use dialog to get numeric new password with separated line strings and cancel return field
    ///
    /// @param[in] heading      Dialog heading
    /// @param[in] line0        Line #0 text
    /// @param[in] line1        Line #1 text
    /// @param[in] line2        Line #2 text
    /// @param[out] canceled    Return value about cancel button
    /// @param[in] noLabel      [opt] label to put on the no button
    /// @param[in] yesLabel     [opt] label to put on the yes button
    /// @return                 Returns True if 'Yes' was pressed, else False
    ///
    ///
    ///-------------------------------------------------------------------------
    ///
    /// **Example:**
    /// ~~~~~~~~~~~~~{.cpp}
    /// #include <kodi/gui/DialogYesNo.h>
    ///
    /// bool canceled;
    /// bool ret = kodi::gui::DialogYesNo::ShowAndGetInput(
    ///    "Yes / No test call",   // The Header
    ///    "You has opened Yes / No dialog for test",
    ///    "",
    ///    "Is this OK for you?",
    ///    canceled,               // return value about cancel button
    ///    "Not really",           // No label, is optional and if empty "No"
    ///    "Ohhh yes");            // Yes label, also optional and if empty "Yes"
    /// fprintf(stderr, "You has called Yes/No, returned '%s' and was %s\n",
    ///          ret ? "yes" : "no",
    ///          canceled ? "canceled" : "not canceled");
    /// ~~~~~~~~~~~~~
    ///
    inline bool ShowAndGetInput(
      const std::string&      heading,
      const std::string&      line0,
      const std::string&      line1,
      const std::string&      line2,
      bool&                   canceled,
      const std::string&      noLabel = "",
      const std::string&      yesLabel = "")
    {
      return ::kodi::addon::CAddonBase::m_interface->toKodi.kodi_gui->dialogYesNo.ShowAndGetInputLineButtonText(::kodi::addon::CAddonBase::m_interface->toKodi.kodiBase, heading.c_str(), line0.c_str(), line1.c_str(), line2.c_str(), canceled, noLabel.c_str(), yesLabel.c_str());
    }
    //--------------------------------------------------------------------------
  };
  /// @}

} /* namespace gui */
} /* namespace kodi */
