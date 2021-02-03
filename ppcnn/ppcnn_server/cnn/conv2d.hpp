/*
 * Copyright 2020 Yamana Laboratory, Waseda University
 * Supported by JST CREST Grant Number JPMJCR1503, Japan.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE‐2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "layer.hpp"

using std::size_t;

const string CONV2D_CLASS_NAME = "Conv2D";

class Conv2D : public Layer
{
public:
    Conv2D(const string& name, const size_t& in_height, const size_t& in_width,
           const size_t& in_channels, const size_t& filter_size,
           const size_t& filter_height, const size_t& filter_width,
           const size_t& stride_height, const size_t& stride_width,
           const string& padding, const string& activation,
           const Plaintext4D& plain_filters,
           const vector<Plaintext>& plain_biases, OptOption& option);
    ~Conv2D();

    const size_t& out_height() const
    {
        return out_height_;
    }
    const size_t& out_width() const
    {
        return out_width_;
    }
    const size_t& out_channels() const
    {
        return out_channels_;
    }

    void printInfo() const override;
    bool isOutOfRangeInput(const int& target_x, const int& target_y) const;
    void forward(Ciphertext3D& input) const;

private:
    size_t in_height_;
    size_t in_width_;
    size_t in_channels_;
    size_t filter_size_;
    size_t filter_height_;
    size_t filter_width_;
    size_t stride_height_;
    size_t stride_width_;
    string padding_;
    string activation_;
    size_t out_height_;
    size_t out_width_;
    size_t out_channels_;
    size_t pad_top_;
    size_t pad_bottom_;
    size_t pad_left_;
    size_t pad_right_;
    Plaintext4D plain_filters_;
    vector<Plaintext> plain_biases_;

    OptOption& option_;
};
