/**
 * \file	provider_system_node.cc
 * \author	Marc-Antoine Couture <coumarc9@outlook.com>
 * \date	06/10/2017
 *
 * \copyright Copyright (c) 2017 S.O.N.I.A. All rights reserved.
 *
 * \section LICENSE
 *
 * This file is part of S.O.N.I.A. software.
 *
 * S.O.N.I.A. software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * S.O.N.I.A. software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with S.O.N.I.A. software. If not, see <http://www.gnu.org/licenses/>.
 */

#include "provider_system/provider_system_node.h"

namespace provider_system {

    //==============================================================================
    // C / D T O R S   S E C T I O N

    //------------------------------------------------------------------------------
    //
    ProviderSystemNode::ProviderSystemNode(const ros::NodeHandlePtr &nh)
        : nh_(nh)
    {


    }

    //------------------------------------------------------------------------------
    //
    ProviderSystemNode::~ProviderSystemNode() {}

    //==============================================================================
    // M E T H O D   S E C T I O N
    //------------------------------------------------------------------------------
    //
    void ProviderSystemNode::Spin() {

      ros::Rate r(0.5);  // 15 hz
      while (ros::ok()) {
        ros::spinOnce();

          checkTemp();

       r.sleep();
      }
    }


    void ProviderSystemNode::checkTemp() {



    }


}  // namespace provider_system
