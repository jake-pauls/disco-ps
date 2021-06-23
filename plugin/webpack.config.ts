import type { Configuration } from 'webpack';
import { sveltePreprocess } from 'svelte-preprocess/dist/autoProcess';

import path from 'path';
import CopyPlugin from 'copy-webpack-plugin';

const config: Configuration = {
  entry: './src/index.ts',
  output: {
    path: path.resolve(__dirname, 'dist'),
    filename: 'index.js',
  },
  externals: {
    uxp: 'commonjs2 uxp',
    photoshop: 'commonjs2 photoshop',
  },
  resolve: {
    alias: {
      svelte: path.resolve('node_modules', 'svelte'),
    },
    extensions: ['.js', '.ts', '.svelte'],
  },
  module: {
    rules: [
      {
        /* Svelte Rules */
        test: /\.svelte$/,
        exclude: /node_modules/,
        use: {
          loader: 'svelte-loader',
          options: {
            /* Emit CSS for Svelte components in build */
            emitCss: true,
            preprocess: sveltePreprocess({}),
          },
        },
      },
      {
        /* TypeScript Rules */
        test: /\.ts$/,
        use: 'ts-loader',
        exclude: /node_modules/,
      },
      {
        /* Prevents errors for Svelte on Webpack 5+ */
        test: /node_modules\/svelte\/.*\.mjs$/,
        resolve: {
          fullySpecified: false,
        },
      },
    ],
  },
  plugins: [
    new CopyPlugin({
      /* Copy manifest and uxp assets into final build */
      patterns: ['public'],
    }),
  ],
};

export default config;
