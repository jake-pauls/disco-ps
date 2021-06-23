/**
 * @type {import("snowpack").SnowpackUserConfig }
 */
export default {
  mount: {
    public: { url: '/', static: true },
    src: { url: '/dist' },
  },
  plugins: [
    '@snowpack/plugin-svelte',
    '@snowpack/plugin-dotenv',
    [
      '@snowpack/plugin-typescript',
      {
        /* Yarn PnP workaround: see https://www.npmjs.com/package/@snowpack/plugin-typescript */
        ...(process.versions.pnp ? { tsc: 'yarn pnpify tsc' } : {}),
      },
    ],
    [
      '@snowpack/plugin-webpack',
      {
        /* Extend webpack build configuration to allow external modules */
        sourceMap: false,
        extendConfig: (config) => {
          config.externals = {
            uxp: 'commonjs2 uxp',
            photoshop: 'commonjs2 photoshop',
          };
          config.output.filename = 'js/[name].js';

          return config;
        },
      },
    ],
  ],
  packageOptions: {
    /* Mark required tools as external in final build */
    external: ['uxp', 'photoshop'],
  },
};
