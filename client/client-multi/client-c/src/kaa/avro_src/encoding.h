/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to you under the Apache License, Version 2.0 
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.  See the License for the specific language governing
 * permissions and limitations under the License. 
 */
#ifndef AVRO_ENCODING_H
#define AVRO_ENCODING_H
#ifdef __cplusplus
extern "C" {
#endif

#include "avro/platform.h"
#include "avro/io.h"

/*
 * TODO: this will need more functions when JSON encoding is added 
 */
struct avro_encoding_t {
    const char *description;
    /*
     * string
     */
    int (*read_string) (avro_reader_t reader, char **s, int64_t *len);
    int (*write_string) (avro_writer_t writer, const char *s);
    /*
     * bytes
     */
    int (*read_bytes) (avro_reader_t reader, char **bytes, int64_t * len);
    int (*write_bytes) (avro_writer_t writer,
                const char *bytes, const int64_t len);
    /*
     * int
     */
    int (*read_int) (avro_reader_t reader, int32_t * i);
    int (*write_int) (avro_writer_t writer, const int32_t i);
    /*
     * long
     */
    int (*read_long) (avro_reader_t reader, int64_t * l);
    int (*write_long) (avro_writer_t writer, const int64_t l);
    /*
     * float
     */
    int (*read_float) (avro_reader_t reader, float *f);
    int (*write_float) (avro_writer_t writer, const float f);
    /*
     * double
     */
    int (*read_double) (avro_reader_t reader, double *d);
    int (*write_double) (avro_writer_t writer, const double d);
    /*
     * boolean
     */
    int (*read_boolean) (avro_reader_t reader, int8_t * b);
    int (*write_boolean) (avro_writer_t writer, const int8_t b);
    /*
     * null
     */
    int (*read_null) (avro_reader_t reader);
    int (*write_null) (avro_writer_t writer);
};
typedef struct avro_encoding_t avro_encoding_t;

#define AVRO_WRITE(writer, buf, len) \
{ int rval = avro_write( writer, buf, len ); if(rval) return rval; }
#define AVRO_READ(reader, buf, len)  \
{ int rval = avro_read( reader, buf, len ); if(rval) return rval; }

extern const avro_encoding_t avro_binary_encoding;    /* in
                             * encoding_binary
                             */
#ifdef __cplusplus
} // extern "C"
#endif
#endif
